use proconio::input;

fn main() {
    input! {
        a: i8,
        b: i8,
        c: i8,
        d: i8,
    }
    if (a, b) <= (c, d) {
        println!("Takahashi");
    } else {
        println!("Aoki");
    }
}
