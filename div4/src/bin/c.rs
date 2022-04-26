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
        let a: Vec<usize> = (0..n).map(|_| scan.next::<usize>()).collect();
        let mut ans = false;
        for even in 0..=1 {
            for odd in 0..=1 {
                let (mut e, mut o) = (true, true);
                a.iter().enumerate().for_each(|(id, val)| {
                    let new_val = if id % 2 == 0 { val + even } else { val + odd };
                    e &= new_val % 2 == 0;
                    o &= new_val % 2 == 1;
                });
                ans |= e || o;
            }
        }
        writeln!(
            out,
            "{}",
            match ans {
                true => "YES",
                false => "NO",
            }
        )
        .ok();
    }
}
