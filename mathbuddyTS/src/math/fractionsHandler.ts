// This file contains the handler for all fraction-related commands

import * as Fractions from './fractions'

export function handleFractionCommand(command: string, args: string[]): string {
    try {
        if (command === "add") {
            console.log("Enter fractions in the format a/b c/d:");
            if (args.length >= 2) {
                const [num1, denom1] = parseFraction(args[0]);
                const [num2, denom2] = parseFraction(args[1]);
                const result = Fractions.addFractions(num1, denom1, num2, denom2);
                return 'Result: ${result[0]}/${result[1]}';
            } else {
                return "Insufficient arguments for add operation.";
            }
            // handle other fraction commands
        }
        return "Command not recognized or not implemented.";   
    } catch (error) {
        return 'Error: ${error.message}';
    }
}

function parseFraction(fraction: string): [number, number] {
    const parts = fraction.split('/');
    if (parts.length !== 2) {
        throw new Error("Invalid fraction format");
    }
    return parts.map(part => parseInt(part, 10)) as [number, number];
}