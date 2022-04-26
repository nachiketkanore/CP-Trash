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
        let n: usize = scan.next();
        let mut a: Vec<usize> = (0..n).map(|_| scan.next::<usize>()).collect();
        a.sort();
        let mut ans: i32 = -1;
        for i in 2..n {
            if a[i - 2] == a[i - 1] && a[i - 1] == a[i] {
                ans = a[i] as i32;
                break;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
