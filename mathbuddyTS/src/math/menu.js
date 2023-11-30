"use strict";
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
exports.startMenu = void 0;
const readline = __importStar(require("readline"));
const fractionsHandler_1 = require("./fractionsHandler");
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
function startMenu() {
    console.log("Enter command 'help' to see a list of commands: ");
    console.log("What would you like to do?");
    rl.on('line', (input) => {
        var _a;
        const args = input.trim().split(' ');
        const command = (_a = args.shift()) !== null && _a !== void 0 ? _a : '';
        processCommand(command, args);
    });
}
exports.startMenu = startMenu;
function processCommand(command, args) {
    if (command === 'fractions') {
        (0, fractionsHandler_1.handleFractionCommand)(args[0], args.slice(1));
    }
    else if (command === 'help') {
        displayHelp();
    }
    else if (command === 'quit') {
        quit();
    }
    else {
        console.log('Invalid command. Enter "help" to see list of commands.');
        console.log("What would you like to do?");
    }
}
function displayHelp() {
    console.log("\nBelow are the commands to operate this program: \n");
    // ... help instructions
    startMenu();
}
function quit() {
    console.log('See you later!');
    rl.close();
}
