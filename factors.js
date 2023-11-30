let number = readInt("What is your number? ");

while (counter < number/2) {
    if (number % counter == 0){
        console.log(counter);
    }
    counter++;
}
