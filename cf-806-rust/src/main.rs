use std::{
    io::Error,
    io::{self, prelude::*},
};

fn a(input: &str) -> String {
    let input: Vec<&str> = input.trim().split('\n').collect();
    input[1..]
        .iter()
        .fold(Vec::new(), |mut res, &line| {
            dbg!(line);
            res.push(match line.to_lowercase().as_str() {
                "yes" => "YES",
                _ => "NO",
            });
            res
        })
        .join("\n")
}

fn read_input() -> Result<String, Error> {
    Ok(io::stdin()
        .lock()
        .lines()
        .fold(String::new(), |mut input, line| {
            input.push_str(&line.unwrap());
            input
        }))
}

fn main() {
    print!("{}", a(read_input().unwrap().as_str()));
}
