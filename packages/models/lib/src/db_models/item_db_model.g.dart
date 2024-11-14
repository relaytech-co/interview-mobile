// GENERATED CODE - DO NOT MODIFY BY HAND

// ignore_for_file: implicit_dynamic_parameter, cast_nullable_to_non_nullable, always_use_package_imports

part of 'item_db_model.dart';

// **************************************************************************
// TypeAdapterGenerator
// **************************************************************************

class ItemDbModelAdapter extends TypeAdapter<ItemDbModel> {
  @override
  final int typeId = 2;

  @override
  ItemDbModel read(BinaryReader reader) {
    final numOfFields = reader.readByte();
    final fields = <int, dynamic>{
      for (int i = 0; i < numOfFields; i++) reader.readByte(): reader.read(),
    };
    return ItemDbModel(
      uid: fields[0] as String,
      barcode: fields[1] as String,
      linkedItemUid: fields[2] as String,
      lastEventUid: fields[3] as String,
      lastEventCourierOperativeUid: fields[4] as String?,
      lastEventTime: fields[5] as DateTime?,
      bagStatus: fields[6] as String?,
      type: fields[7] as String?,
    );
  }

  @override
  void write(BinaryWriter writer, ItemDbModel obj) {
    writer
      ..writeByte(8)
      ..writeByte(0)
      ..write(obj.uid)
      ..writeByte(1)
      ..write(obj.barcode)
      ..writeByte(2)
      ..write(obj.linkedItemUid)
      ..writeByte(3)
      ..write(obj.lastEventUid)
      ..writeByte(4)
      ..write(obj.lastEventCourierOperativeUid)
      ..writeByte(5)
      ..write(obj.lastEventTime)
      ..writeByte(6)
      ..write(obj.bagStatus)
      ..writeByte(7)
      ..write(obj.type);
  }

  @override
  int get hashCode => typeId.hashCode;

  @override
  bool operator ==(Object other) =>
      identical(this, other) ||
      other is ItemDbModelAdapter &&
          runtimeType == other.runtimeType &&
          typeId == other.typeId;
}
