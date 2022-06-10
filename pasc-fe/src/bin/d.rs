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

    let tcs = scan.next::<usize>();
    for _ in 0..tcs {
        let n = scan.next::<usize>();
        let mut a = vec![0; 101];
        for _ in 0..n {
            let u = scan.next::<usize>();
            a[u] += 1;
        }
        writeln!(
            out,
            "{}",
            match (0usize..=100)
                .filter(|&val| a[val] > 0 && a[val] % 2 == 0)
                .count()
            {
                0 => "YES",
                _ => "NO",
            }
        )
        .ok();
    }
}
