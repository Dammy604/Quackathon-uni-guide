// Basic Calculator with Square Function

// Function to add two numbers
function add(a, b) {
    return a + b;
  }
  
  // Function to subtract two numbers
  function subtract(a, b) {
    return a - b;
  }
  
  // Function to multiply two numbers
  function multiply(a, b) {
    return a * b;
  }
  
  // Function to divide two numbers
  function divide(a, b) {
    if (b === 0) {
      return 'Error: Division by zero';
    }
    return a / b;
  }
  
  // Function to calculate the square of a number
  function square(a) {
    return a * a;
  }
  
  // Function to handle user input and perform the chosen operation
  function calculator() {
    const operation = prompt("Choose an operation: add, subtract, multiply, divide, square");
    let result;
  
    if (operation === 'square') {
      const num = parseFloat(prompt("Enter the number to square:"));
      result = square(num);
    } else {
      const num1 = parseFloat(prompt("Enter the first number:"));
      const num2 = parseFloat(prompt("Enter the second number:"));
  
      switch (operation) {
        case 'add':
          result = add(num1, num2);
          break;
        case 'subtract':
          result = subtract(num1, num2);
          break;
        case 'multiply':
          result = multiply(num1, num2);
          break;
        case 'divide':
          result = divide(num1, num2);
          break;
        default:
          result = 'Invalid operation';
      }
    }
  
    alert(`Result: ${result}`);
  }
  
  // Start the calculator
  calculator();
  