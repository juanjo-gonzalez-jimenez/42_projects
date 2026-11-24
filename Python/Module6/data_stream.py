import abc
import typing


class DataProcessor(abc.ABC):

    def __init__(self, name: str) -> None:
        self._data: list[str] = []
        self._rank = 0
        self._name = name
        self._counter = 0

    @abc.abstractmethod
    def validate(self, data: typing.Any) -> bool:

        pass

    @abc.abstractmethod
    def ingest(self, data: typing.Any) -> None:

        pass

    def output(self) -> tuple[int, str]:

        value = self._data.pop(0)
        rank = self._rank
        self._rank += 1
        return (rank, value)

    def _append_counter(self, data: str) -> None:

        self._data.append(data)
        self._counter += 1

    def get_name(self) -> str:

        return self._name

    def get_counter(self) -> int:

        return self._counter

    def get_remaining(self) -> int:

        return len(self._data)


class NumericProcessor(DataProcessor):

    def __init__(self) -> None:
        super().__init__("Numeric Processor")

    def validate(self, data: typing.Any) -> bool:

        if isinstance(data, (int, float)):
            return True
        if isinstance(data, list):
            for i in data:
                if not isinstance(i, (int, float)):
                    return False
            return True
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:

        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, list):
            for item in data:
                self._append_counter(str(item))
        else:
            self._append_counter(str(data))


class TextProcessor(DataProcessor):

    def __init__(self) -> None:
        super().__init__("Text Processor")

    def validate(self, data: typing.Any) -> bool:

        if isinstance(data, str):
            return True
        if isinstance(data, list):
            for i in data:
                if not isinstance(i, str):
                    return False
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:

        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, list):
            for item in data:
                self._append_counter(item)
        else:
            self._append_counter(data)


class LogProcessor(DataProcessor):

    def __init__(self) -> None:
        super().__init__("Log Processor")

    def _is_log(self, entry: typing.Any) -> bool:

        if not isinstance(entry, dict):
            return False
        for key, value in entry.items():
            if not isinstance(key, str) or not isinstance(value, str):
                return False
        return True

    def validate(self, data: typing.Any) -> bool:

        if isinstance(data, dict):
            return self._is_log(data)
        if isinstance(data, list):
            for i in data:
                if not self._is_log(i):
                    return False
            return True
        return False

    def _format_log(self, entry: dict[str, str]) -> str:

        return f"{entry['log_level']}: {entry['log_message']}"

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:

        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, list):
            for entry in data:
                self._append_counter(self._format_log(entry))
        else:
            self._append_counter(self._format_log(data))


class DataStream:

    def __init__(self) -> None:
        self._proc_list: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:

        self._proc_list.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:

        for item in stream:
            for proc in self._proc_list:
                if proc.validate(item):
                    proc.ingest(item)
                    break
            else:
                print("DataStream error - Can't process "
                      f"element in stream: {item}")

    def print_processors_stats(self) -> None:

        print("== DataStream statistics ==")
        if not self._proc_list:
            print("No processor found, no data")
            print()
        else:
            for proc in self._proc_list:
                print(f"{proc.get_name()}: total "
                      f"{proc.get_counter()} items processed, remaining "
                      f"{proc.get_remaining()} on processor")
            print()


if __name__ == "__main__":

    print("=== Code Nexus - Data Stream ===")
    print()
    print("Initialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()
    print("Registering Numeric Processor")
    numeric = NumericProcessor()
    stream.register_processor(numeric)
    batch: list[typing.Any] = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {"log_level": "WARNING",
             "log_message": "Telnet access! Use ssh instead"},
            {"log_level": "INFO",
             "log_message": "User wil is connected"},
        ],
        42,
        ["Hi", "five"],
    ]
    print(f"Send first batch of data on stream: {batch}")
    stream.process_stream(batch)
    stream.print_processors_stats()
    print("Registering other data processors")
    text = TextProcessor()
    log = LogProcessor()
    stream.register_processor(text)
    stream.register_processor(log)
    print("Send the same batch again")
    stream.process_stream(batch)
    stream.print_processors_stats()
    print("Consume some elements from the data processors: "
          "Numeric 3, Text 2, Log 1")
    for _ in range(3):
        numeric.output()
    for _ in range(2):
        text.output()
    log.output()
    stream.print_processors_stats()
