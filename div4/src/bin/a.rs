use std::io::{stdin, stdout, BufWriter, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    let t: usize = scan.next();
    for _ in 0..t {
        writeln!(
            out,
            "{}",
            match scan.next::<i32>() {
                -5000..=1399 => "Division 4",
                1400..=1599 => "Division 3",
                1600..=1899 => "Division 2",
                1900..=5000 => "Division 1",
                _ => panic!("Invalid input"),
            }
        )
        .ok();
    }
}
