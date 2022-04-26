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
        let m: usize = scan.next();
        let mut mat: Vec<Vec<char>> = vec![vec!['x'; m]; n];
        for i in 0..n {
            let row: Vec<char> = scan.next::<String>().chars().collect();
            assert_eq!(row.len(), m);
            for j in 0..m {
                mat[i][j] = row[j];
            }
        }
        loop {
            let mut found = false;
            for i in 0..n - 1 {
                for j in 0..m {
                    if mat[i][j] == '*' && mat[i + 1][j] == '.' {
                        found = true;
                        mat[i][j] = '.';
                        mat[i + 1][j] = '*';
                    }
                }
            }
            if !found {
                break;
            }
        }
        for i in 0..n {
            for j in 0..m {
                write!(out, "{}", mat[i][j]).ok();
            }
            write!(out, "\n").ok();
        }
    }
}
