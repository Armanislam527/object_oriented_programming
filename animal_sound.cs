public class animal{
    public string name {get;set;}
    public animal(string name){
        Name = name;
    }
    public virtual string speak(){
        return " I am a animal.";
    }
}
class program{
    static vaoid Main(string[] args){
        animal dog = new animal("dog");
        console.WriteLine(dog.speak());
    }
}