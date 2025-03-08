console.log('Hello World');


const adding = document.getElementById("add");
const subtracting = document.getElementById("subtract");
const multiplying = document.getElementById("multiply");
const dividing = document.getElementById("divide");
const summingOfSquares = document.getElementById("sumOfSquares");
const resultDisplay = document.getElementById("result");


adding.addEventListener("click", function()
{
    const number1 = parseFloat(document.getElementById("num1").value);
    const number2 = parseFloat(document.getElementById("num2").value);

    if (!isNaN(number1) && !isNaN(number2))
    {
        const sum = number1 + number2;
        resultDisplay.textContent = `Result: ${sum}`;
    }

    else 
    {
        resultDisplay.textContent = 'Please enter valid numbers';
    }


});

subtracting.addEventListener("click", function()
{
    const number1 = parseFloat(document.getElementById("num1").value);
    const number2 = parseFloat(document.getElementById("num2").value);

    if (!isNaN(number1) && !isNaN(number2))
    {
        const difference = number1 - number2;
        resultDisplay.textContent = `Result: ${difference}`;
    }
    
    else 
    {
        resultDisplay.textContent = 'Please enter valid numbers';
    }

})

multiplying.addEventListener("click", function()
{
    const number1 = parseFloat(document.getElementById("num1").value);
    const number2 = parseFloat(document.getElementById("num2").value);

    if (!isNaN(number1) && !isNaN(number2))
    {
        const product = number1 * number2;
        resultDisplay.textContent = `Result: ${product}`;
    }
    
    else 
    {
        resultDisplay.textContent = 'Please enter valid numbers';
    }

})

dividing.addEventListener("click", function()
{
    const number1 = parseFloat(document.getElementById("num1").value);
    const number2 = parseFloat(document.getElementById("num2").value);

    if (!isNaN(number1) && !isNaN(number2))
    {
        const quotient = number1/number2;
        resultDisplay.textContent = `Result: ${quotient}`;
    }
    
    else 
    {
        resultDisplay.textContent = 'Please enter valid numbers';
    }

})

summingOfSquares.addEventListener("click", function()
{
    const number1 = parseFloat(document.getElementById("num1").value);
    const number2 = parseFloat(document.getElementById("num2").value);

    if (!isNaN(number1) && !isNaN(number2))
    {
        const squaresSum = (number1 * number1) + (number2 * number2);
        resultDisplay.textContent = `Result: ${squaresSum}`;
    }
    
    else 
    {
        resultDisplay.textContent = 'Please enter valid numbers';
    }

})

