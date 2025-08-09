package todo
import todo.savingFunctions.*
import todo.taskFunctions.*
import java.io.File

fun main() {
    var choice = 0;
    var exit = 0;
    println("Working dir: ${File("").absolutePath}")

    while(exit == 0) {
        println("ToDo App:");
        println("1) Add task");
        println("2) List task/s");
        println("3) Change task status");
        println("4) Delete task");
        println("5) Exit");
        println("\n What do you wanna do: ");
        choice = readln().toInt();

        when (choice) {
            1 -> addTask(mainFile);
            2 -> listTasks();
            3 -> changeStatus(mainFile);
            4 -> deleteTask(mainFile);
            5 -> exit++;
            else -> println("Invalid option");
        }
    }
}
