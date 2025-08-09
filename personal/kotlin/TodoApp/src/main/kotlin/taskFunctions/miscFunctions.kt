package todo.taskFunctions
import java.io.File

fun getId(file: File): Int {
    val tasks = taskList(file);
    val maxId = tasks.maxOfOrNull {it.id} ?: 0;
    return maxId + 1;
}

fun waitForUser() {
    println("\nPress Enter to continue...");
    readln();
}