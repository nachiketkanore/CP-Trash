from typing import Tuple

def decode_dss_signature(signature: bytes) -> Tuple[int, int]: ...
def encode_dss_signature(r: int, s: int) -> bytes: ...

class Prehashed(object): ...
