import abc
import typing


class DataProcessor(abc.ABC):

    def __init__(self) -> None:
        self._data: list[str] = []
        self._rank = 0

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


class NumericProcessor(DataProcessor):

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
                self._data.append(str(item))
        else:
            self._data.append(str(data))


class TextProcessor(DataProcessor):

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
                self._data.append(item)
        else:
            self._data.append(data)


class LogProcessor(DataProcessor):

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
                self._data.append(self._format_log(entry))
        else:
            self._data.append(self._format_log(data))


if __name__ == "__main__":

    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    print("=== Code Nexus - Data Processor ===")
    print()
    print("Testing Numeric Processor...")
    print(f"Trying to validate input '42': {numeric.validate(42)}")
    print(f"Trying to validate input 'Hello': {numeric.validate('Hello')}")
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        numeric.ingest("foo")
    except ValueError as e:
        print(f"Got exception: {e}")
    numbers: list[int | float] = [1, 2, 3, 4, 5]
    print(f"Processing data: {numbers}")
    numeric.ingest(numbers)
    print("Extracting 3 values...")
    for _ in range(3):
        rank, value = numeric.output()
        print(f"Numeric value {rank}: {value}")
    print()
    print("Testing Text Processor...")
    text = TextProcessor()
    print(f"Trying to validate input '42': {text.validate(42)}")
    words = ["Hello", "Nexus", "World"]
    print(f"Processing data: {words}")
    text.ingest(words)
    print("Extracting 1 value...")
    rank, value = text.output()
    print(f"Text value {rank}: {value}")
    print()
    print("Testing Log Processor...")
    log = LogProcessor()
    print(f"Trying to validate input 'Hello': {log.validate('Hello')}")
    logs = [
        {"log_level": "NOTICE", "log_message": "Connection to server"},
        {"log_level": "ERROR", "log_message": "Unauthorized access!!"},
    ]
    print(f"Processing data: {logs}")
    log.ingest(logs)
    print("Extracting 2 values...")
    for _ in range(2):
        rank, value = log.output()
        print(f"Log entry {rank}: {value}")
