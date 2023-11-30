import * as readline from 'readline';
import { handleFractionCommand } from './fractionsHandler';

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

export function startMenu(): void {
    console.log("Enter command 'help' to see a list of commands: ");
    console.log("What would you like to do?");

    rl.on('line', (input) => {
        const args = input.trim().split(' ');
        const command = args.shift() ?? '';
        processCommand(command, args);
    })
}

function processCommand(command: string, args: string[]): void {
    if (command === 'fractions') {
        handleFractionCommand(args[0], args.slice(1));
    } else if (command === 'help') {
        displayHelp();
    } else if (command === 'quit') {
        quit();
    } else {
        console.log('Invalid command. Enter "help" to see list of commands.');
        console.log("What would you like to do?");
    }
}

function displayHelp(): void {
    console.log("\nBelow are the commands to operate this program: \n");
    // ... help instructions
    startMenu();
}

function quit(): void {
    console.log('See you later!');
    rl.close();
}
