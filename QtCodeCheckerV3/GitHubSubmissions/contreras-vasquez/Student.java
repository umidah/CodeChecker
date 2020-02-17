import java.io.File;

public class Student {
    private String name;
    private String studentFile;

    public String getName() {
        return name;
    }
    public void setName(String studentName){
        int length;
        length = studentName.length();
        if(studentName.endsWith(".cpp")){
            name = studentName.substring(0,length-4);
        }
        else if(studentName.endsWith(".java")){
            name = studentName.substring(0,length-5);
        }
    }
    public String getStudentFile(){
        return studentFile;
    }

    public void setStudentFile(String path){
        studentFile = path;
    }
}

