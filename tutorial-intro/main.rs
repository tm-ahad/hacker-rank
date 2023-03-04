use std::env;
use std::fs::File;
use std::io::{self, BufRead, Write};

/*
 * Complete the 'introTutorial' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER V
 *  2. INTEGER_ARRAY arr
 */

fn introTutorial(V: i32, arr: &[i32]) -> i32 {
    let mut i: usize = 0;
    
    while i < arr.len() {
        println!("{} {}", arr[i], V);
        if arr[i] == V {
            return i as i32
        }
        
        i+=1;
    }
    
    -1
}

fn main() {
    let stdin = io::stdin();
    let mut stdin_iterator = stdin.lock().lines();

    let mut fptr = File::create(env::var("OUTPUT_PATH").unwrap()).unwrap();

    let V = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    let n = stdin_iterator.next().unwrap().unwrap().trim().parse::<i32>().unwrap();

    let arr: Vec<i32> = stdin_iterator.next().unwrap().unwrap()
        .trim_end()
        .split(' ')
        .map(|s| s.to_string().parse::<i32>().unwrap())
        .collect();

    let result = introTutorial(V, &arr);

    writeln!(&mut fptr, "{}", result).ok();
}
S
