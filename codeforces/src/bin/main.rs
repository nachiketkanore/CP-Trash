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

const MOD: i64 = 10_i64.pow(9) + 7;

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    let n = scan.next::<usize>();
    let mut multiples = vec![vec![0; 2]; 21];
    for p2 in 0..21 {
        for p3 in 0..2 {
            multiples[p2][p3] = n / ((1 << p2) * 3_usize.pow(p3.try_into().unwrap()));
        }
    }
    let mut dp = vec![vec![0i64; 2]; 21];
    let mut p2 = 0;
    for bit in 0..22 {
        if (1 << bit) <= n {
            p2 = bit;
        }
    }
    dp[p2][0] = 1;
    if (1 << (p2 - 1)) * 3 <= n {
        dp[p2 - 1][1] = 1;
    }
    for i in 0..n - 1 {
        let mut ndp = vec![vec![0i64; 2]; 21];
        for p2 in 0..21 {
            for p3 in 0..2 {
                // choice 1: keep GCD constant by inserting a multiple of GCD
                {
                    let mul = multiples[p2][p3] as i32 - (i as i32 + 1 as i32);
                    ndp[p2][p3] += dp[p2][p3] * mul as i64;
                    ndp[p2][p3] %= MOD;
                }
                // choice 2: reduce GCD by 2 by inserting a multiple of GCD / 2
                if p2 > 0 {
                    let mul = multiples[p2 - 1][p3] as i32 - multiples[p2][p3] as i32;
                    ndp[p2 - 1][p3] += dp[p2][p3] * mul as i64;
                    ndp[p2 - 1][p3] %= MOD;
                }
                // choice 3: reduce GCD by 3 by inserting a multiple of GCD / 3
                if p3 > 0 {
                    let mul = multiples[p2][p3 - 1] as i32 - multiples[p2][p3] as i32;
                    ndp[p2][p3 - 1] += dp[p2][p3] * mul as i64;
                    ndp[p2][p3 - 1] %= MOD;
                }
            }
        }
        dp = ndp;
    }
    writeln!(out, "{}", dp[0][0]).ok();
}
