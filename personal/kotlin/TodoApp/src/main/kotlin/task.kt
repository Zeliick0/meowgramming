package todo
import java.io.File
import kotlinx.serialization.*
import kotlinx.serialization.json.*

@Serializable
data class Task(
    var id: Int = 0,
    val name: String = "",
    val description: String = "",
    var status: Status = Status.PENDING
)

enum class Status {
    PENDING,
    IN_PROGRESS,
    DONE
}

fun getId(): Int {
    val tasks = taskList();
    val maxId = tasks.maxOfOrNull {it.id} ?: 0;
    return maxId + 1;
}

fun waitForUser() {
    println("\nPress Enter to continue...");
    readln();
}

fun addTask() {
    println("Name the task: ");
    val name = readlnOrNull().toString();

    println("Describe the task: ");
    val description = readlnOrNull().toString();

    val newTask = Task(
        id = getId(),
        name = name,
        description = description,
        status = Status.PENDING
    )
    
    saveToJson(newTask);
}

fun listAllTasks() {
    val tasks = taskList();
    tasks.forEach { task ->
        println("Task ${task.name}:\n Id:${task.id}\n Desc:${task.description}\n Status:[${task.status}]");
    }
    waitForUser();
}

fun listATask() {
    val tasks = taskList();
    println("Input task Id: ");
    val input = readln().toInt();

    tasks.forEach { task ->
        if (task.id == input) {
            println("Task ${task.name}:\n Id:${task.id}\n Desc:${task.description}\n Status:[${task.status}]");
        }
    }
    waitForUser();
}

fun listADefinedTask(Id: Int) {
    val tasks = taskList();

    tasks.forEach { task ->
        if (task.id == Id) {
            println("${task.name}:\n Id:${task.id}\n Desc:${task.description}\n Status:[${task.status}]");
        }
    }
}

fun listTasks() {
    val tasks = taskList();
    var choice = 1;

    println(" 1) List all tasks \n 2) List a specific task \n (Default is 1): ");
    val inputChoice = readLine()?.trim()
    choice = if (inputChoice.isNullOrEmpty()) 1 else inputChoice.toInt()

    when (choice) {
        1 -> {
           listAllTasks();
        }
        2 -> {
          listATask();
        }
        else -> {
            println("Invalid choice")
        }
    }
}

fun deleteTask() {
    val tasks = taskList().toMutableList();
    println("Which task to be deleted? (Id):");
    val choice = readln().toInt();

    val taskToDelete = tasks.find {it.id == choice}
    if (taskToDelete != null) {
        tasks.remove(taskToDelete);
        println("Successfully removed the task");
    }

    val updatedData = tasksToJson(tasks);
    file.writeText(updatedData);
}

fun changeStatus() {
    val tasks = taskList();
    println("Which task to update? (Id): ");
    val choice = readln().toInt();

    val taskToUpdate = tasks.find {it.id == choice}
    if (taskToUpdate != null) {
        println("Editing task: ");
        listADefinedTask(taskToUpdate.id);
        println("Change the status to 1) In progress\n 2) Done\n 3) Stop editing");
        val statusUpdate = readln().toInt();

        when (statusUpdate) {
            1 -> {
                taskToUpdate.status = Status.IN_PROGRESS;
                val updatedData = tasksToJson(tasks);
                file.writeText(updatedData);
                println("Successfully updated the task");
            }
            2 -> {
                taskToUpdate.status = Status.DONE;
                val updatedData = tasksToJson(tasks);
                file.writeText(updatedData);
                println("Successfully updated the task");
            }
            3 -> {
                println("Oki")
            }
            else -> {
                println("Invalid choice")
            }
        }
    }
}