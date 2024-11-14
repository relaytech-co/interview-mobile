enum TraceNames {
  login('login'),
  updateApp('update_app'),
  refreshInventoryButton('refresh_inventory_button'),
  goToSeeFullBags('go_to_see_full_bags'),
  goToSeeEmptyBags('go_to_see_empty_bags'),
  goToSeeParcels('go_to_see_parcels'),
  goToSeeItemCategory('go_to_see_item_category'),
  goToSeeItem('go_to_see_item'),
  customerDropOff('customer_drop_off'),
  courierDropOff('courier_drop_off'),
  allowPermission('allow_permission'),
  maybePermission('maybe_permission'),
  courierDropOffBack('courier_drop_off_back'),
  manualCheckIn('manual_check_in'),
  ;

  const TraceNames(this.name);

  final String name;
}

enum TraceTypes {
  btn('btn'),
  inkWell('ink_well'),
  link('link');

  const TraceTypes(this.name);

  final String name;
}
