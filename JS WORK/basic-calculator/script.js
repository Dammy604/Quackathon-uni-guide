
function getNumbers() 
{
    const number1 = parseFloat(document.getElementById('num1'));
    const number2 = parseFloat(document.getElementById('num2'));
    return {number1, number2};
}

function calculate(operation) 
{
    const {number1, number2} = getNumbers();
    let result;

    if (isNaN(number1) || isNaN(number2))
    {
        return "Please enter valid numbers. ";
    }

    switch (operation) {
        case 'add':
            result = number1 + number2;
            break;

        case 'subtract':
            result = number1 + number2;
            break;

        case 'multiply':
            result = number1 + number2;
            break;

        case 'divide':
            result = number2 !==0 ?  number1/number2:"Cannot divide by zero.";
            break;

    
        default:
            result = "Invalid operation.";
    }

    return result;

    
}

document.getElementById('add').addEventListener('click',() => {document.getElementById('result').textContent = `Result: ${calculate('add')}`});
document.getElementById('subtract').addEventListener('click',() => {document.getElementById('result').textContent = `Result: ${calculate('subtract')}`});
document.getElementById('multiply').addEventListener('click',() => {document.getElementById('result').textContent = `Result: ${calculate('multiply')}`});
document.getElementById('divide').addEventListener('click',() => {document.getElementById('result').textContent = `Result: ${calculate('divide')}`});

