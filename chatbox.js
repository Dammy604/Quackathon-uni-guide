function sendMessage() {
    let userInput = document.getElementById("user-input").value;
    let chatBox = document.getElementById("chat-box");

    if (userInput.trim() === "") return;

    // Display user message
    let userMessage = document.createElement("div");
    userMessage.className = "user-message";
    userMessage.textContent = userInput;
    chatBox.appendChild(userMessage);

    // Generate bot response
    let botResponse = getBotResponse(userInput);

    let botMessage = document.createElement("div");
    botMessage.className = "bot-message";
    botMessage.textContent = botResponse;
    chatBox.appendChild(botMessage);

    // Scroll to the latest message
    chatBox.scrollTop = chatBox.scrollHeight;

    // Clear input field
    document.getElementById("user-input").value = "";
}

function getBotResponse(input) {
    let responses = {
        "hello": "Hi there! How can I assist you?",
        "how are you": "I'm just a bot, but I'm doing great! How about you?",
        "bye": "Goodbye! Have a great day!",
        "what is your name": "I'm a simple chatbot created with JavaScript!"
    };

    input = input.toLowerCase();
    return responses[input] || "I'm not sure how to respond to that. Try asking something else!";
}
