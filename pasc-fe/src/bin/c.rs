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
    let mut n = scan.next::<i32>();
    n = n * n;

    let x1 = scan.next::<i32>();
    let y1 = scan.next::<i32>();
    let x2 = scan.next::<i32>();
    let y2 = scan.next::<i32>();

    let dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

    writeln!(
        out,
        "{}",
        match dist <= n {
            true => "YES",
            false => "NO",
        }
    )
    .ok();
}
