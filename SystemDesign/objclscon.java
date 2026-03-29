class Student{
    String name;
    int age;
Student(String name, int age){
    this.name = name;
    this.age = age;
}
}

public class objclscon{
    public static void main(String[] args){
      Student s1 = new Student("chitranshi",3);
      System.out.println(s1.name);
    }

}

