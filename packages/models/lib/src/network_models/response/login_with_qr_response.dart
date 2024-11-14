// ignore_for_file: public_member_api_docs

import 'package:json_annotation/json_annotation.dart';

part 'login_with_qr_response.g.dart';

@JsonSerializable(createToJson: true)
class LoginWithQrResponse {
  const LoginWithQrResponse({
    required this.name,
    required this.email,
    required this.uid,
    required this.jwtToken,
  });

  factory LoginWithQrResponse.fromJson(Map<String, dynamic> json) =>
      _$LoginWithQrResponseFromJson(json);

  /// The name of the pitstop.
  @JsonKey(name: 'pitstop_name')
  final String name;

  /// The email of the pitstop.
  @JsonKey(name: 'pitstop_email')
  final String email;

  /// The id of the pitstop.
  @JsonKey(name: 'pitstop_uid')
  final String uid;

  /// The jwt token of the pitstop.
  @JsonKey(name: 'jwt_token')
  final String jwtToken;

  Map<String, dynamic> toJson() => _$LoginWithQrResponseToJson(this);
}
