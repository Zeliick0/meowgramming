package todo.taskFunctions
import todo.savingFunctions.*
import java.io.File

fun deleteTask(file: File) {
    val tasks = taskList(file).toMutableList();
    println("Which task to be deleted? (Id):");
    val choice = readln().toInt();

    val taskToDelete = tasks.find {it.id == choice}
    if (taskToDelete != null) {
        tasks.remove(taskToDelete);
        println("Successfully removed the task");
    }

    val updatedData = taskListToJson(tasks);
    file.writeText(updatedData);
    updateTaskListIds(mainFile);
}
fun deleteTaskById(file: File, id: Int) {
    val tasks = taskList(file).toMutableList();

    val taskToDelete = tasks.find {it.id == id}
    if (taskToDelete != null) {
        tasks.remove(taskToDelete);
    }

    val updatedData = taskListToJson(tasks);
    file.writeText(updatedData);
    updateTaskListIds(mainFile);
}

fun updateTaskListIds(file: File) {
    val tasks = taskList(file).toMutableList();

    if (tasks[0].id > 1) {
        tasks[0].id = 1;
    }

    for (i in 0..tasks.size - 2) {
        if (tasks[i + 1].id - tasks[i].id == 2) {
            for (j in i+1 until tasks.size){
                tasks[j].id -= 1;
            }
        }
    }
    val updatedData = taskListToJson(tasks);
    file.writeText(updatedData);
}

fun moveTask(file: File, task :Task) {
    val max = getId(file);

    task.id = max;
    saveToJson(task, file);
}