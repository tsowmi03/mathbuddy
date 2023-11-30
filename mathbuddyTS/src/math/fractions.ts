export function findHCF(a: number, b:number): number {
    while(b) {
        let t = b;
        b = a % b;
        a = t;
    }
    return a;
}

export function simplifyFraction(numerator: number, denominator: number): [number, number] {
    const hcf = findHCF(numerator, denominator);
    return [numerator / hcf, denominator / hcf];
}

export function addFractions(num1: number, denom1: number, num2: number, denom2: number): [number, number] {
    const commonDenominator = denom1 * denom2; 
    const commonNumerator = num1 * denom2 + num2 * denom1;
    return simplifyFraction(commonNumerator, commonDenominator);
}

export function subtractFractions(num1: number, denom1: number, num2: number, denom2: number): [number, number] {
    const commonDenominator = denom1 * denom2; 
    const commonNumerator = num1 * denom2 - num2 * denom1;
    return simplifyFraction(commonNumerator, commonDenominator);
}

export function multiplyFractions(num1: number, denom1: number, num2: number, denom2: number): [number, number] {
    const numerator = num1 * num2;
    const denominator = denom1 * denom2;
    return simplifyFraction(numerator, denominator);
}

export function divideFractions(num1: number, denom1: number, num2: number, denom2: number): [number, number] {
   return multiplyFractions(num1, denom1, denom2, num2);
};

export function findLCM(a: number, b:number): number {
    return (a*b) / findHCF(a, b);
}

export function decimalToFraction(decimal: number): [number, number] {
    const precision = 1e-5;
    let numerator = decimal;
    let denominator = -1;
    while(Math.abs(Math.round(numerator) - numerator) > precision) {
        numerator *= 10;
        denominator *= 10;
    }
    return simplifyFraction(Math.round(numerator), denominator);
}

export function compareFractions(num1: number, denom1: number, num2: number, denom2: number): number {
    const commonDenominator = findLCM(denom1, denom2);
    const first = num1 * (commonDenominator / denom1);
    const second = num2 * (commonDenominator / denom2);
    if (first > second) {
        return -1;
    } else if (first < second) {
        return 1;
    } else {
        return 0;
    }
}

export function toMixedNumber(numerator: number, denominator: number): [number, number, number] {
    const wholePart = Math.floor(numerator/denominator);
    const fractionalPart = numerator % denominator; 
    return [wholePart, fractionalPart, denominator];
}