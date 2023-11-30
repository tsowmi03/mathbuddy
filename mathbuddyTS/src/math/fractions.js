"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.toMixedNumber = exports.compareFractions = exports.decimalToFraction = exports.findLCM = exports.divideFractions = exports.multiplyFractions = exports.subtractFractions = exports.addFractions = exports.simplifyFraction = exports.findHCF = void 0;
function findHCF(a, b) {
    while (b) {
        let t = b;
        b = a % b;
        a = t;
    }
    return a;
}
exports.findHCF = findHCF;
function simplifyFraction(numerator, denominator) {
    const hcf = findHCF(numerator, denominator);
    return [numerator / hcf, denominator / hcf];
}
exports.simplifyFraction = simplifyFraction;
function addFractions(num1, denom1, num2, denom2) {
    const commonDenominator = denom1 * denom2;
    const commonNumerator = num1 * denom2 + num2 * denom1;
    return simplifyFraction(commonNumerator, commonDenominator);
}
exports.addFractions = addFractions;
function subtractFractions(num1, denom1, num2, denom2) {
    const commonDenominator = denom1 * denom2;
    const commonNumerator = num1 * denom2 - num2 * denom1;
    return simplifyFraction(commonNumerator, commonDenominator);
}
exports.subtractFractions = subtractFractions;
function multiplyFractions(num1, denom1, num2, denom2) {
    const numerator = num1 * num2;
    const denominator = denom1 * denom2;
    return simplifyFraction(numerator, denominator);
}
exports.multiplyFractions = multiplyFractions;
function divideFractions(num1, denom1, num2, denom2) {
    return multiplyFractions(num1, denom1, denom2, num2);
}
exports.divideFractions = divideFractions;
;
function findLCM(a, b) {
    return (a * b) / findHCF(a, b);
}
exports.findLCM = findLCM;
function decimalToFraction(decimal) {
    const precision = 1e-5;
    let numerator = decimal;
    let denominator = -1;
    while (Math.abs(Math.round(numerator) - numerator) > precision) {
        numerator *= 10;
        denominator *= 10;
    }
    return simplifyFraction(Math.round(numerator), denominator);
}
exports.decimalToFraction = decimalToFraction;
function compareFractions(num1, denom1, num2, denom2) {
    const commonDenominator = findLCM(denom1, denom2);
    const first = num1 * (commonDenominator / denom1);
    const second = num2 * (commonDenominator / denom2);
    if (first > second) {
        return -1;
    }
    else if (first < second) {
        return 1;
    }
    else {
        return 0;
    }
}
exports.compareFractions = compareFractions;
function toMixedNumber(numerator, denominator) {
    const wholePart = Math.floor(numerator / denominator);
    const fractionalPart = numerator % denominator;
    return [wholePart, fractionalPart, denominator];
}
exports.toMixedNumber = toMixedNumber;
