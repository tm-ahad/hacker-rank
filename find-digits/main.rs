use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'findDigits' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

fn findDigits(n: i32) -> i32 {
    let s: String = n.to_string();
    let mut ind: i32 = 0;
    
    for c in s.chars() {
        let i: i32 = c.to_string().parse().unwrap();
        
        if i == 0 {
            continue
        }
        else if n % i == 0 {
            ind+=1;
        }
    }
    
    ind
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let t = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    for _ in 0..t {
        let n = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

        let result = findDigits(n);

        writeln!(&mut fptr, "{}", result).ok();
    }
}

