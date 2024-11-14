extension CommonIterableExtensions<T> on Iterable<T> {
  /// Inserts [element] between each element in this list.
  ///
  /// [] => []
  /// [a] => [a]
  /// [a,b] => [a, element, b]
  /// [a,b,c] => [a, element, b, element, c]
  /// ...
  Iterable<T> insertBetween(T element) sync* {
    final iterator = this.iterator;

    // empty list
    if (!iterator.moveNext()) return;

    var previous = iterator.current;
    while (iterator.moveNext()) {
      yield previous;
      yield element;
      previous = iterator.current;
    }
    yield previous;
  }

  Iterable<T> insertBetweenIndexed(
    T Function(int index) itemBuilder,
  ) sync* {
    final iterator = this.iterator;

    // empty list
    if (!iterator.moveNext()) return;

    var previous = iterator.current;
    var index = 0;
    while (iterator.moveNext()) {
      yield previous;
      yield itemBuilder(index);
      previous = iterator.current;
      index += 1;
    }
    yield previous;
  }

  /// Iterates through the elements returning the non-null
  /// transformed elements of this sequence.
  Iterable<U> compactMap<U>(U? Function(T e) toElement) {
    return expand((element) {
      final newElement = toElement(element);
      return [
        if (newElement != null) newElement,
      ];
    });
  }

  /// Converts this into a [List.unmodifiable].
  List<T> toUnmodifiableList() => List<T>.unmodifiable(this);

  /// Converts this into a [Set.unmodifiable].
  Set<T> toUnmodifiableSet() => Set<T>.unmodifiable(this);
}
