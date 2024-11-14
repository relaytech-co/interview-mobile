import 'package:analytics_client/analytics_client.dart';
import 'package:app_ui/app_ui.dart';
import 'package:flutter/material.dart';
import 'package:flutter_riverpod/flutter_riverpod.dart';
import 'package:go_router/go_router.dart';
import 'package:models/models.dart';
import 'package:relay_interview/i18n/strings.g.dart';
import 'package:relay_interview/src/manual_check_in/domain/check_in_item.dart';
import 'package:relay_interview/src/manual_check_in/domain/manual_check_in_controller.dart';

class CreateManualCheckInPage extends ConsumerStatefulWidget {
  const CreateManualCheckInPage({super.key});

  @override
  ConsumerState<CreateManualCheckInPage> createState() =>
      _ManualCheckInPageState();
}

class _ManualCheckInPageState extends ConsumerState<CreateManualCheckInPage> {
  late String itemType;
  TextEditingController barcodeController = TextEditingController();
  TextEditingController courierController = TextEditingController();

  @override
  void initState() {
    super.initState();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
        appBar: AppBar(
          title: const Text('Manual Check In'),
        ),
        floatingActionButtonLocation: FloatingActionButtonLocation.centerFloat,
        floatingActionButton: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 16),
            child: RFilledButton(
                onPressed: () {
                  final type = const ItemTypeConverter().fromJson(itemType);
                  ref
                      .read(checkedInItemsControllerProvider.notifier)
                      .create(CheckInItem(
                        barcode: barcodeController.text,
                        courierId: courierController.text,
                        type: type,
                      ));
                  context.pop();
                },
                expand: true,
                traceName: TraceNames.manualCheckIn.name,
                child: Text(t.checkin))),
        body: Padding(
            padding: const EdgeInsets.symmetric(horizontal: 16),
            child: Column(
              children: [
                const Spacer2(),
                Row(children: [
                  Assets.images.relayLogo.image(height: 40),
                  const Spacer1(),
                  const Text(
                      'This is a screen designed for Manual Check-In of items arriving at the pitstop. '),
                ]),
                const Spacer2(),
                TextFormField(
                  controller: barcodeController,
                  decoration: const InputDecoration(
                    border: OutlineInputBorder(),
                    labelText: 'Barcode',
                    hintText: 'REL123123MOP',
                  ),
                ),
                const Spacer2(),
                TextFormField(
                  controller: courierController,
                  decoration: const InputDecoration(
                    border: OutlineInputBorder(),
                    labelText: 'Courier Id',
                    hintText: 'REL6MAVI',
                  ),
                ),
                const Spacer2(),
                RadioListTile(
                    value: t.fullBags,
                    groupValue: itemType,
                    title: Text(t.fullBags,
                        style: Theme.of(context)
                            .textTheme
                            .bodyMedium!
                            .copyWith(fontSize: 16)),
                    onChanged: (String? val) {
                      if (val != null) {
                        setState(() {
                          itemType = val;
                        });
                      }
                    }),
                RadioListTile(
                    value: t.emptyBags,
                    groupValue: itemType,
                    title: Text(t.emptyBags,
                        style: Theme.of(context)
                            .textTheme
                            .bodyMedium!
                            .copyWith(fontSize: 16)),
                    onChanged: (String? val) {
                      if (val != null) {
                        setState(() {
                          itemType = val;
                        });
                      }
                    }),
                RadioListTile(
                    value: t.parcel,
                    groupValue: itemType,
                    title: Text(t.parcel,
                        style: Theme.of(context)
                            .textTheme
                            .bodyMedium!
                            .copyWith(fontSize: 16)),
                    onChanged: (String? val) {
                      if (val != null) {
                        setState(() {
                          itemType = val;
                        });
                      }
                    }),
              ],
            )));
  }
}
