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

    def __init__(self):
        super().__init__()

class TextProcessor(DataProcessor):

    def __init__(self):
        super().__init__()

class LogProcessor(DataProcessor):

    def __init__(self):
        super().__init__()