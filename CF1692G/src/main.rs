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
    let t = scan.next::<usize>();

    for _ in 0..t {
        let n = scan.next::<usize>();
        let k = scan.next::<usize>();
        let mut a = vec![0; n + 1];
        (1..=n).for_each(|i| a[i] = scan.next::<i32>());
        (1..n).for_each(|i| a[i] = (a[i] < 2 * a[i + 1]) as i32 + a[i - 1]);
        a[n] = 0;
        writeln!(
            out,
            "{}",
            (1..=n - k)
                .filter(|id| a[id + k - 1] - a[id - 1] >= k as i32)
                .count()
        )
        .ok();
    }
}
