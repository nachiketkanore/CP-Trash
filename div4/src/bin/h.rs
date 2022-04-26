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
        let mut k: u32 = scan.next();
        let mut cnt = vec![0u32; 31];
        (0..n).for_each(|_| {
            let val: u32 = scan.next();
            for bit in 0..31 {
                cnt[bit] += (val >> bit & 1) as u32;
            }
        });
        writeln!(
            out,
            "{}",
            (0..31).rev().fold(0, |mut acc, bit| {
                let req = n as u32 - cnt[bit];
                if req as u32 <= k {
                    acc |= 1 << bit;
                    k -= req;
                }
                acc
            })
        )
        .ok();
    }
}
