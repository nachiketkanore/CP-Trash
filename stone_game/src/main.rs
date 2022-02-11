use std::io;

fn read_line() -> Vec<usize> {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    line.trim()
        .split('\n')
        .filter(|line| line.len() > 0)
        .map(|val| val.trim().parse::<usize>().unwrap())
        .collect()
}

fn main() {
    let t = read_line()[0];
    for _ in 0..t {
        let n = read_line()[0];
        let a = read_line();
        assert!(a.len() == n);
        let mut ans = n;
        for i in 0..n {
            for j in i..n {
                let mut ok = true;
                for k in i..=j {
                    if a[k] == 1 || a[k] == n {
                        ok = false;
                        break;
                    }
                }
                if ok {
                    if ans > n - (j - i + 1) {
                        ans = n - (j - i + 1);
                    }
                }
            }
        }
        println!("{}", ans);
    }
}
