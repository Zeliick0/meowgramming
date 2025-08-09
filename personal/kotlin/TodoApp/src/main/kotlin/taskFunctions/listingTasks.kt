package todo.taskFunctions
import todo.savingFunctions.*
import java.io.File

fun taskList(file: File): List<Task> {
    if (!file.exists() || file.readText().isBlank()) {
        return emptyList();
    }

    val taskData = file.readText();
    return jsonToTask(taskData);
}
fun listAllTasks(file: File) {
    val tasks = taskList(file);
    tasks.forEach { task ->
        println("Task ${task.name}:\n Id:${task.id}\n Desc:${task.description}\n Status:[${task.status}]");
    }
    waitForUser();
}

fun listATask(file: File) {
    val tasks = taskList(file);
    println("Input task Id: ");
    val input = readln().toInt();

    tasks.forEach { task ->
        if (task.id == input) {
            println("Task ${task.name}:\n Id:${task.id}\n Desc:${task.description}\n Status:[${task.status}]");
        }
    }
    waitForUser();
}

fun listTaskById(id: Int, file: File) {
    val tasks = taskList(file);

    tasks.forEach { task ->
        if (task.id == id) {
            println("${task.name}:\n Id:${task.id}\n Desc:${task.description}\n Status:[${task.status}]");
        }
    }
}

fun listTasks() {
    println(" 1) List all tasks \n 2) List a specific task \n 3) List done tasks \n (Default is 1): ");
    val inputChoice = readlnOrNull()?.trim()
    val choice = if (inputChoice.isNullOrEmpty()) 1 else inputChoice.toInt()

    when (choice) {
        1 -> {
            listAllTasks(mainFile);
        }
        2 -> {
            listATask(mainFile);
        }
        3 -> {
            listAllTasks(doneFile);
        }
        else -> {
            println("Invalid choice")
        }
    }
}