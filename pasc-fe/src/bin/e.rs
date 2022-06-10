use std::cmp::min;
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
        let mut jumps = vec![vec![0, 0]; 2];
        jumps[0][0] = scan.next::<i32>();
        jumps[1][0] = scan.next::<i32>();
        jumps[0][1] = scan.next::<i32>();
        jumps[1][1] = scan.next::<i32>();

        const INF: i64 = 10i64.pow(18);
        let mut dp = vec![INF; n + 1];
        dp[0] = 0;

        for i in 1..=n {
            for jump in &jumps {
                let (j, cost) = (jump[0], jump[1] as i64);
                if i as i32 - j as i32 >= 0 {
                    dp[i] = min(dp[i], cost + dp[i as usize - j as usize]);
                }
            }
        }

        writeln!(
            out,
            "{}",
            match dp[n] >= INF {
                true => format!("NO"),
                false => format!("YES\n{}", dp[n]),
            }
        )
        .ok();
    }
}
