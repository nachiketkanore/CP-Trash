use std::collections::BTreeSet;
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
        let n: usize = scan.next();
        let mut k: usize = scan.next();
        if n == 1 {
            writeln!(out, "{}", 0).ok();
            continue;
        }
        let mut g = vec![BTreeSet::<usize>::new(); n];
        for _ in 0..n - 1 {
            let mut u: usize = scan.next();
            let mut v: usize = scan.next();
            u -= 1;
            v -= 1;
            g[u].insert(v);
            g[v].insert(u);
        }
        let mut leaves = Vec::<usize>::new();
        let mut remain = BTreeSet::<usize>::new();
        for i in 0..n {
            remain.insert(i);
            if g[i].len() == 1 {
                leaves.push(i);
            }
        }

        while !leaves.is_empty() && k > 0 {
            k -= 1;
            let mut nleaves = Vec::<usize>::new();
            for leaf in leaves {
                let mut who = n;
                remain.remove(&leaf);
                for v in g[leaf].clone() {
                    g[v].remove(&leaf);
                    who = v;
                }
                if who != n {
                    g[leaf].remove(&who);
                    if g[who].len() == 1 {
                        nleaves.push(who);
                    }
                }
            }
            leaves = nleaves;
        }
        writeln!(out, "{}", remain.len()).ok();
    }
}
