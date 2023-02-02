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

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

function timeConversion(s: string): string {
    let len = s.length;
    let spl = s.split(":")
    let hour = Number(spl[0])
    let ampm = s[len-2] + s[len-1]
    
    if (ampm == "PM" && hour != 12) {
        hour += 12
    }
    else if (hour == 12 && ampm != "PM") {
        hour = 0
    }
    
    return `${hour > 10 ? hour: `0${hour}`}:${spl[1]}:${spl[2].replace("PM", "").replace("AM", "")}`
}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const s: string = readLine();

    const result: string = timeConversion(s);

    ws.write(result + '\n');

    ws.end();
}
