'use strict';

import { WriteStream, createWriteStream } from "fs";
process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString: string = '';
let inputLines: string[] = [];
let currentLine: number = 0;

process.stdin.on('data', function(inputStdin: string): void {
    inputString += inputStdin;
});

process.stdin.on('end', function(): void {
    inputLines = inputString.split('\n');
    inputString = '';

    main();
});

function readLine(): string {
    return inputLines[currentLine++];
}

const rep = (s: string, n: number): string => {
    let i = 0;
    let res = "";
    
    while (i < n) {
        for (let c of s) {
            res += c
        }
        
        i++
    }
    
    return res
}

/*
 * Complete the 'repeatedString' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. LONG_INTEGER n
 */

const repeatedString = (s: string, n: number): number => {
    if (s == 'a') { return n }
    let factor = n % s.length
    let ass = 0
    let len = s.length;
    
    for (let ch of s) {
        if (ch == 'a') {
            ass++
        }
    }
    
    if (factor== 0) {
        let c = 0;
        return (ass * n)/len
        
    } else {
        let can = n - factor
        let ext = s.slice(0, factor)
        let exl = 0
        
        for (let ch of ext) {
            if (ch == 'a') {
                exl++
            }
        }
        
        
        console.log("Sigma as well.", ass, n, factor, ext)
        return (ass * can / len) + exl
    }
}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const s: string = readLine();

    const n: number = parseInt(readLine().trim(), 10);

    const result: number = repeatedString(s, n);

    ws.write(result + '\n');

    ws.end();
}

