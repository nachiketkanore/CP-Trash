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
        let a: Vec<Vec<char>> = (0..n)
            .map(|_| scan.next::<String>().chars().collect())
            .collect();
        let mut counter = vec![vec![0usize; 12]; 12];
        let mut ans = 0;
        for i in 0..n {
            assert_eq!(a[i].len(), 2);
            let (first, second) = (
                a[i][0] as usize - 'a' as usize,
                a[i][1] as usize - 'a' as usize,
            );
            for two in 'a'..='k' {
                if a[i][1] != two {
                    ans += counter[first][two as usize - 'a' as usize];
                }
            }
            for one in 'a'..='k' {
                if a[i][0] != one {
                    ans += counter[one as usize - 'a' as usize][second];
                }
            }
            counter[first][second] += 1;
        }
        writeln!(out, "{}", ans).ok();
    }
}
