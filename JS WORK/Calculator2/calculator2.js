console.log('Hello World!');


const adding = document.getElementById("add");
const subtracting = document.getElementById("subtract");
const multiplying = document.getElementById("multiply");
const dividing = document.getElementById("divide");
const summingOfSquares = document.getElementById("sumOfSquares");
const resultDisplay = document.getElementById("result");


function getNumbers()
{
    const number1 = parseFloat(document.getElementById('num1').value);
    const number2 = parseFloat(document.getElementById('num2').value);
    return {number1, number2};
}

function getResult(operation) {

    const {number1, number2} = getNumbers();
    let result;

    if (isNaN(number1) || isNaN(number2)){
        return "Please enter valid numbers!";
    }

    switch (operation) {
        case 'add':
            result = number1 + number2;
            break;

        case 'subtract':
            result = number1 - number2;
            break;

        case 'multiply':
            result = number1 * number2;
            break;

        case 'divide':
            result = number1 / number2;
            break;

        case 'sumOfSquares':
            result = number1 + number2;
            break;
            
        default:
            break;
    }
    
}