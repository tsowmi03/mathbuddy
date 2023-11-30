"use strict";
// This file contains the handler for all fraction-related commands
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.handleFractionCommand = void 0;
const Fractions = __importStar(require("./fractions"));
function handleFractionCommand(command, args) {
    try {
        if (command === "add") {
            console.log("Enter fractions in the format a/b c/d:");
            if (args.length >= 2) {
                const [num1, denom1] = parseFraction(args[0]);
                const [num2, denom2] = parseFraction(args[1]);
                const result = Fractions.addFractions(num1, denom1, num2, denom2);
                return 'Result: ${result[0]}/${result[1]}';
            }
            else {
                return "Insufficient arguments for add operation.";
            }
            // handle other fraction commands
        }
        return "Command not recognized or not implemented.";
    }
    catch (error) {
        return 'Error: ${error.message}';
    }
}
exports.handleFractionCommand = handleFractionCommand;
function parseFraction(fraction) {
    const parts = fraction.split('/');
    if (parts.length !== 2) {
        throw new Error("Invalid fraction format");
    }
    return parts.map(part => parseInt(part, 10));
}
