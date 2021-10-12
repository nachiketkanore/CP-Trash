struct Person<'a> {
    name: &'a str,
}

impl<'a> Person<'a> {
    fn hello(&self) {
        println!("Hello world, name = {}", self.name);
    }
}

fn main() {
    let _person = Person { name: "Nachiket" };
    _person.hello();
}
