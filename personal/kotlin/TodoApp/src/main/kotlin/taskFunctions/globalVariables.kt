package todo.taskFunctions
import kotlinx.serialization.Serializable
import java.io.File

val mainFile = File("src/main/resources/tasks.json");
val doneFile = File("src/main/resources/doneTasks.json");
@Serializable
data class Task(
    var id: Int = 0,
    val name: String = "",
    val description: String = "",
    var status: Status = Status.PENDING
)

data class doneTask(
    var id: Int,
    val name: String,
    val description: String,
    var status: Status
)

enum class Status {
    PENDING,
    IN_PROGRESS,
    DONE
}