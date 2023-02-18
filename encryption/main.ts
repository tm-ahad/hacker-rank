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
 * Complete the 'encryption' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

function encryption(s: string): string {
    let res = ""
    let len = s.length
    let c = Math.ceil(Math.sqrt(len))
    let stat = Math.ceil(Math.sqrt(len))
    let h = Math.ceil(len/stat)
    let hh = 0
    
    console.log(stat, h)
    
    
    while (c != 0) {
        let curr = ""
        let point = hh
        let br = 1;
        
        while (br != h+1) {
            
            curr += s[point] || ""
            point += stat
            br++
        }
        res += ` ${curr}`
        
        hh++
        c--
    }
    
    return res.slice(1, res.length)

}

function main() {
    const ws: WriteStream = createWriteStream(process.env['OUTPUT_PATH']);

    const s: string = readLine();

    const result: string = encryption(s);

    ws.write(result + '\n');

    ws.end();
}

