#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# Function to run a test
run_test() {
    local test_name="$1"
    local input="$2"
    local expected="$3"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    echo -e "${BLUE}Test $TOTAL_TESTS: $test_name${NC}"
    echo "Input: $input"
    
    # Run the program and capture output
    actual=$(./convert "$input" 2>&1)
    
    # Compare expected vs actual
    if [ "$actual" = "$expected" ]; then
        echo -e "${GREEN}✓ PASSED${NC}"
        PASSED_TESTS=$((PASSED_TESTS + 1))
    else
        echo -e "${RED}✗ FAILED${NC}"
        echo -e "${YELLOW}Expected:${NC}"
        echo "$expected"
        echo -e "${YELLOW}Actual:${NC}"
        echo "$actual"
        FAILED_TESTS=$((FAILED_TESTS + 1))
    fi
    echo "----------------------------------------"
}

# Check if program exists
if [ ! -f "./convert" ]; then
    echo -e "${RED}Error: ./convert not found. Please compile first with 'make'${NC}"
    exit 1
fi

echo -e "${BLUE}=== ScalarConverter Comprehensive Test Suite ===${NC}"
echo

# Test 1: Character 'a'
run_test "Printable Character 'a'" "'a'" "char: 'a'
int: 97
float: 97.0f
double: 97.0"

# Test 2: Character '0' (zero character, not zero number)
run_test "Character '0'" "'0'" "char: '0'
int: 48
float: 48.0f
double: 48.0"

# Test 3: Character '*' (matches example)
run_test "Character '*'" "'*'" "char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 4: Non-displayable character (null)
run_test "Non-displayable Character" $'\'\\0\'' "char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# Test 5: Integer 0 (matches example)
run_test "Integer 0" "0" "char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# Test 6: Integer 42
run_test "Integer 42" "42" "char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 7: Negative integer
run_test "Negative Integer -42" "-42" "char: impossible
int: -42
float: -42.0f
double: -42.0"

# Test 8: Integer 65 (ASCII 'A')
run_test "Integer 65 (ASCII A)" "65" "char: 'A'
int: 65
float: 65.0f
double: 65.0"

# Test 9: Integer 127 (ASCII boundary)
run_test "Integer 127" "127" "char: Non displayable
int: 127
float: 127.0f
double: 127.0"

# Test 10: Integer 128 (out of char range)
run_test "Integer 128" "128" "char: impossible
int: 128
float: 128.0f
double: 128.0"

# Test 11: Float 42.0f (matches example)
run_test "Float 42.0f" "42.0f" "char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 12: Float 0.0f
run_test "Float 0.0f" "0.0f" "char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# Test 13: Negative float
run_test "Negative Float -4.2f" "-4.2f" "char: impossible
int: -4
float: -4.2f
double: -4.2"

# Test 14: Float with fractional part
run_test "Float 3.14f" "3.14f" "char: impossible
int: 3
float: 3.1f
double: 3.1"

# Test 15: Double 42.0
run_test "Double 42.0" "42.0" "char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 16: Double 0.0
run_test "Double 0.0" "0.0" "char: Non displayable
int: 0
float: 0.0f
double: 0.0"

# Test 17: Negative double
run_test "Negative Double -4.2" "-4.2" "char: impossible
int: -4
float: -4.2f
double: -4.2"

# Test 18: Double with more precision
run_test "Double 3.14159" "3.14159" "char: impossible
int: 3
float: 3.1f
double: 3.1"

# Test 19: NaN (matches example)
run_test "NaN" "nan" "char: impossible
int: impossible
float: nanf
double: nan"

# Test 20: NaN float
run_test "NaN Float" "nanf" "char: impossible
int: impossible
float: nanf
double: nan"

# Test 21: Positive infinity
run_test "Positive Infinity" "+inf" "char: impossible
int: impossible
float: +inff
double: +inf"

# Test 22: Negative infinity
run_test "Negative Infinity" "-inf" "char: impossible
int: impossible
float: -inff
double: -inf"

# Test 23: Positive infinity float
run_test "Positive Infinity Float" "+inff" "char: impossible
int: impossible
float: +inff
double: +inf"

# Test 24: Negative infinity float
run_test "Negative Infinity Float" "-inff" "char: impossible
int: impossible
float: -inff
double: -inf"

# Test 25: Invalid input - letters
run_test "Invalid Input - Letters" "abc" "char: impossible
int: impossible
float: impossible
double: impossible"

# Test 26: Invalid character format
run_test "Invalid Character Format" "'ab'" "char: impossible
int: impossible
float: impossible
double: impossible"

# Test 27: Empty string
run_test "Empty String" "" "char: impossible
int: impossible
float: impossible
double: impossible"

# Test 28: Multiple decimal points
run_test "Multiple Decimal Points" "4.2.1" "char: impossible
int: impossible
float: impossible
double: impossible"

# Test 29: Invalid float format
run_test "Invalid Float Format" "4.2ff" "char: impossible
int: impossible
float: impossible
double: impossible"

# Test 30: Just decimal point
run_test "Just Decimal Point" "." "char: impossible
int: impossible
float: impossible
double: impossible"

# Test 31: Integer overflow
run_test "Integer Overflow" "2147483648" "char: impossible
int: impossible
float: impossible
double: impossible"

# Test 32: Large negative integer
run_test "Large Negative Integer" "-2147483649" "char: impossible
int: impossible
float: impossible
double: impossible"

# Test 33: Float without decimal
run_test "Float without decimal" "42f" "char: impossible
int: impossible
float: impossible
double: impossible"

# Test 34: Double with 'f' suffix
run_test "Double with f suffix" "42.0ff" "char: impossible
int: impossible
float: impossible
double: impossible"

# Test 35: Leading plus sign integer
run_test "Leading Plus Integer" "+42" "char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 36: Leading plus sign float
run_test "Leading Plus Float" "+42.0f" "char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 37: Leading plus sign double
run_test "Leading Plus Double" "+42.0" "char: '*'
int: 42
float: 42.0f
double: 42.0"

# Test 38: Space character
run_test "Space Character" "' '" "char: ' '
int: 32
float: 32.0f
double: 32.0"





echo
echo -e "${BLUE}=== Test Results ===${NC}"
echo -e "Total Tests: ${TOTAL_TESTS}"
echo -e "${GREEN}Passed: ${PASSED_TESTS}${NC}"
echo -e "${RED}Failed: ${FAILED_TESTS}${NC}"

if [ $FAILED_TESTS -eq 0 ]; then
    echo -e "${GREEN}🎉 All tests passed! Your ScalarConverter is working correctly!${NC}"
    exit 0
else
    echo -e "${RED}❌ Some tests failed. Please review the implementation.${NC}"
    exit 1
fi