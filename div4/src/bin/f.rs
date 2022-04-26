use std::cmp::max;
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
        let mut pref = vec![0u32; n + 1];
        let mut suff = vec![0u32; n + 1];
        for i in 1..=n {
            pref[i] = scan.next();
            suff[i] = pref[i];
            pref[i] += pref[i - 1];
        }
        for i in (1..=n - 1).rev() {
            suff[i] += suff[i + 1];
        }
        let mut ans = 0;
        for i in 1..=n {
            let (mut lo, mut hi, mut best) = (i + 1, n, 0);
            while lo <= hi {
                let mid = (lo + hi) / 2;
                if suff[mid] == pref[i] {
                    best = mid;
                    hi = mid - 1;
                } else if suff[mid] > pref[i] {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            if best > 0 {
                assert_eq!(pref[i], suff[best]);
                ans = max(ans, i + (n - best + 1));
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}
