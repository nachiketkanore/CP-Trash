use std::io;

const MOD: i64 = 998244353;

fn solve(n: i64) -> i64 {
    let mut tens = vec![1];
    (0..18).for_each(|_| {
        tens.push(tens.last().unwrap() * 10);
    });
    assert!(tens.last().unwrap() == &(1e18 as i64));
    let mut ans: i64 = 0;
    for i in 1..tens.len() {
        let l = tens[i - 1];
        let r = tens[i] - 1;
        if n >= r {
            let mut tot = r - l + 1;
            tot %= MOD;
            tot = tot * (tot + 1) / 2;
            tot %= MOD;
            ans += tot;
            ans %= MOD;
        } else if n >= l {
            let mut tot = n - l + 1;
            tot %= MOD;
            tot = tot * (tot + 1) / 2;
            tot %= MOD;
            ans += tot;
            ans %= MOD;
        } else {
            break;
        }
    }
    ans
}

fn main() {
    let mut line = String::new();
    io::stdin()
        .read_line(&mut line)
        .expect("unable to read line");
    let n: i64 = line.trim().parse().unwrap();
    println!("{}", solve(n));
}

#[test]
fn samples() {
    assert_eq!(solve(16), 73);
    assert_eq!(solve(238), 13870);
    assert_eq!(solve(999999999999999999), 762062362);
}
