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

    def validate(self, data) -> bool:

        if data is int or float:
            return True
        if data is list:
            for i in data:
                if i is not int or not float:
                    return False
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:

        if self.validate is False:
            raise ValueError("Imprper numeric data")
        if data is list:
            for item in data:
                self._data.str
        

class TextProcessor(DataProcessor):

    def __init__(self):
        super().__init__()

class LogProcessor(DataProcessor):

    def __init__(self):
        super().__init__()