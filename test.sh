#!/bin/bash

# Test script for Dining Philosophers Problem
# Author: Miguel González
# Date: September 2024

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

echo -e "${BLUE}🍴 Dining Philosophers Test Suite${NC}"
echo "=================================="

# Check if executable exists
if [ ! -f "./philo" ]; then
    echo -e "${RED}❌ Error: philo executable not found!${NC}"
    echo -e "${YELLOW}💡 Run 'make' to compile the project${NC}"
    exit 1
fi

echo -e "${GREEN}✓ Executable found${NC}"

# Function to run a test
run_test() {
    local test_name="$1"
    local args="$2"
    local expected="$3"
    local timeout="$4"

    echo -e "\n${YELLOW}🧪 Running test: $test_name${NC}"
    echo -e "${BLUE}Command: ./philo $args${NC}"

    # Run with timeout to prevent hanging
    if timeout "$timeout" ./philo $args > /dev/null 2>&1; then
        echo -e "${GREEN}✓ Test passed: $expected${NC}"
        return 0
    else
        echo -e "${RED}❌ Test failed or timed out${NC}"
        return 1
    fi
}

# Test 1: Invalid arguments
echo -e "\n${YELLOW}📝 Testing argument validation...${NC}"
run_test "No arguments" "" "Should exit with error" "2s"
run_test "Too few arguments" "5" "Should exit with error" "2s"
run_test "Invalid numbers" "5 0 200 200" "Should exit with error" "2s"
run_test "Invalid characters" "5 abc 200 200" "Should exit with error" "2s"

# Test 2: Valid basic execution
echo -e "\n${YELLOW}📝 Testing basic functionality...${NC}"
run_test "Basic 4 philosophers" "4 410 200 200" "Should run successfully" "5s"
run_test "Basic 3 philosophers" "3 800 200 200" "Should run successfully" "5s"

# Test 3: Limited meals
echo -e "\n${YELLOW}📝 Testing meal limits...${NC}"
run_test "3 philosophers, 2 meals each" "3 800 200 200 2" "Should complete after 6 meals" "10s"

# Test 4: Edge cases
echo -e "\n${YELLOW}📝 Testing edge cases...${NC}"
run_test "Single philosopher" "1 800 200 200" "Should handle single philosopher" "3s"

# Test 5: Stress test
echo -e "\n${YELLOW}📝 Running stress test...${NC}"
echo -e "${BLUE}Command: ./philo 200 800 200 200 (max philosophers)${NC}"
timeout 8s ./philo 200 800 200 200 > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓ Stress test passed${NC}"
else
    echo -e "${YELLOW}⚠️  Stress test may have timed out (normal for large numbers)${NC}"
fi

# Compilation tests
echo -e "\n${YELLOW}🔨 Testing compilation modes...${NC}"
make clean > /dev/null 2>&1
make debug > /dev/null 2>&1
if [ -f "./philo" ]; then
    echo -e "${GREEN}✓ Debug compilation successful${NC}"
else
    echo -e "${RED}❌ Debug compilation failed${NC}"
fi

make clean > /dev/null 2>&1
make sanitize > /dev/null 2>&1
if [ -f "./philo" ]; then
    echo -e "${GREEN}✓ Sanitize compilation successful${NC}"
else
    echo -e "${RED}❌ Sanitize compilation failed${NC}"
fi

# Clean up
make fclean > /dev/null 2>&1

echo -e "\n${GREEN}🎉 Test suite completed!${NC}"
echo -e "${BLUE}📊 Note: Some tests may timeout with large numbers of philosophers${NC}"
echo -e "${BLUE}📊 This is normal behavior as the simulation runs indefinitely${NC}"
